#!/bin/bash



git add .
git commit -m "update"

git push origin master
expect "Username for 'https://github.com':"
send "luigy-mach"

expect "Password for 'https://luigy-mach@github.com':"
send "luigy1mach"




