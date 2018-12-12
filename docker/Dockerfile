FROM nvidia/cuda:9.1-cudnn7-runtime-ubuntu16.04

ENV REFRESHED_AT 2018-12-04

LABEL io.k8s.description="Headless VNC Container with Xfce window manager, firefox and chromium" \
      io.k8s.display-name="Headless VNC Container based on Ubuntu" \
      io.openshift.expose-services="6901:http,5901:xvnc" \
      io.openshift.tags="vnc, ubuntu, xfce" \
      io.openshift.non-scalable=true

ENV DISPLAY=:1 \
    VNC_PORT=5901 \
    NO_VNC_PORT=6901
EXPOSE $VNC_PORT $NO_VNC_PORT

ENV HOME=/headless \
    TERM=xterm \
    STARTUPDIR=/dockerstartup \
    INST_SCRIPTS=/headless/install \
    NO_VNC_HOME=/headless/noVNC \
    DEBIAN_FRONTEND=noninteractive \
    VNC_COL_DEPTH=24 \
    VNC_RESOLUTION=1280x1024 \
    VNC_PW=vncpassword \
    VNC_VIEW_ONLY=false
WORKDIR $HOME

ADD ./src/common/install/ $INST_SCRIPTS/
ADD ./src/ubuntu/install/ $INST_SCRIPTS/
RUN find $INST_SCRIPTS -name '*.sh' -exec chmod a+x {} +

RUN $INST_SCRIPTS/tools.sh
ENV LANG='en_US.UTF-8' LANGUAGE='en_US:en' LC_ALL='en_US.UTF-8'

RUN $INST_SCRIPTS/tigervnc.sh
RUN $INST_SCRIPTS/no_vnc.sh

RUN $INST_SCRIPTS/firefox.sh
RUN $INST_SCRIPTS/chrome.sh

RUN $INST_SCRIPTS/xfce_ui.sh
ADD ./src/common/xfce/ $HOME/

RUN $INST_SCRIPTS/libnss_wrapper.sh
ADD ./src/common/scripts $STARTUPDIR
RUN $INST_SCRIPTS/set_user_permission.sh $STARTUPDIR $HOME

USER 1984

ENTRYPOINT ["/dockerstartup/vnc_startup.sh"]
CMD ["--tail-log"]

