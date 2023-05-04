#!/bin/bash

# Architecture, os & kernel version
archi=$(uname -a)
# CPU physical, numb of processors
cpup=$(cat /proc/cpuinfo | grep "physical id" | wc -l)
# CPU virtual, numb of processors
cpuv=$(cat /proc/cpuinfo | grep processor | wc -l)
# Memory Usage, avail RAM and util rate
mem=$(free -m | grep Mem | awk '{ printf("%s/%sMB (%.2f%%)", $3, $2, ($3/$2/100)) }')
# Disk Usage, avail disk and util rate
disk=$(df -h --total | grep total | awk '{ printf("%.1f/%.fGb (%s)", $3, $2, $5) }')
# CPU load, util rate of processors
cpul=$(top -bn1 | grep Cpu | awk '{ printf("%1f%%", $2 + $4) }')
# Last boot, date and time of the last reboot
lboot=$(uptime -s | awk '{ printf("%s %s", $1, substr($2, 1, length($2) - 3)) }')
# LVM use, LVM active or not
lvm=$(lsblk | grep lvm | wc -l | awk '{ if ($1){ printf("yes"); exit; } else print "no" } ')
# Connections TCP (need to install, `net-tools`), numb of active connection
tcp=$(netstat -an | grep ESTABLISHED | wc -l)
# User log, numb of users using the server
log=$(users | wc -w)
# IP (IPv4) address for Network
ip=$(hostname -I)
# MAC (Media Access Control) address for Network
mac=$(cat /sys/class/net/enp0s3/address)
# Numb of commands executed with the sudo program
odus=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# wall - write a message to all users
wall "  #Architecture: $archi
        #CPU physical: $cpup
        #vCPU: $cpuv
        #Memory Usage: $mem
        #Disk Usage: $disk
        #CPU load: $cpul
        #Last boot: $lboot
        #LVM use: $lvm
        #Connections TCP: $tcp
        #User log: $log
        #Network: IP $ip ($mac)
        #Sudo: $odus cmd"
