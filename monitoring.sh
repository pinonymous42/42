#!/bin/bash
wall $'#Architecture: '`uname -a`\
$'\n#CPU physical: '`cat /proc/cpuinfo | grep 'physical id' | wc -l`\
$'\n#vCPU: '`cat /proc/cpuinfo | grep 'physical id' | wc -l`\
$'\n'`free -m | awk 'NR==2 {printf "#Memory Usage: %sMB/%sMB (%.2f%%)", $3, $2, $3*100/$2}'`\
$'\n'`df -h | awk '$NF=="/" {printf "#Disk Usage: %sB/%sB (%s)", $3, $2, $5}'`\
$'\n'`top -bn1 | grep 'load' | awk '{printf "#CPU Load: %.2f%%", $(NF-2)}'`\
$'\n'`who -b | awk '{print "#Last boot: "$2" "$3}'`\
$'\n'`lsblk | grep 'lvm' | awk '{if($1){print"#LVM use: yes"; exit;} else{print "#LVM use: no"}}'`\
$'\n#Connection TCP: '`netstat -an | grep 'ESTABLISHED' | wc -l`\
$'\n#User log: '`who | wc -l`\
$'\n#Network: IP' `hostname -I` "(" `ip a | grep 'link/ether' | awk '{print $2}'` ")"\
$'\n#Sudo: '`grep 'sudo' /var/log/auth.log | wc -l`
