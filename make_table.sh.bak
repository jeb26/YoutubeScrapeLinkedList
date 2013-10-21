#!/bin/bash

while read x; do
	v=`expr "$x" : '.*data-context-item-views=\"\([0-9,]* [a-zA-Z]*\)\"'`
	v1=${v//views/}
	view=${v1//,/}
	user=`expr "$x" : '.*data-context-item-user=\"\([a-zA-Z0-9 -]*\)\"'`
	id=`expr "$x" : '.*data-context-item-id=\"\([a-zA-Z0-9_]*\)\"'`
	duration=`expr "$x" : '.*data-context-item-time=\"\([0-9,]*\:[0-9,]*\)\"'`
	title=`expr "$x" : '.*data-context-item-title=\"\([a-zA-Z0-9 -(),?!&#;:.|]*\)\"'`


	echo -e "${user}\t${view}\t${duration}\t${id}\t${title}"
done
