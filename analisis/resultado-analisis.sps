* Encoding: UTF-8.


GET DATA
  /TYPE=XLSX
  /FILE='C:\Users\USER\Desktop\video-out-txt\Libro2.xlsx'
  /SHEET=name 'Hoja1'
  /CELLRANGE=FULL
  /READNAMES=ON
  /DATATYPEMIN PERCENTAGE=95.0
  /HIDDEN IGNORE=YES.
EXECUTE.
DATASET NAME ConjuntoDatos3 WINDOW=FRONT.
