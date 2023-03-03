# Prepare for Evaluation

## Part 1: Questions

Why Debian?
- It's easier to install and configure than CentOS (and i haven't use CentOS befoe)

What is virtual machine?
- A Virtual Machine (VM) is a compute resource that uses software instead of a physical computer to run programs and deploy apps. Each virtual machine runs its own operating system and functions separately from the other VMs, even when they are all running on the same host. For example, you can run a virtual MacOS machine on a physical PC. 

What it's purpose?
- VMs may be deployed to accommodate different levels of processing power needs, to run software that requires a different operating system, or to test applications in a safe, sandboxed environment. 

How does it works?
- VM working through "Virtualization" technology. Virtualization uses software to simulate virtual hardware that allows VMs to run on a single host machine.

Diff between aptitude and apt?
- Aptitude is a high-level package manager while APT is lower-level package manager which can be used by other  higher-level package managers 
- (read more: https://www.tecmint.com/difference-between-apt-and-aptitude/)

What is AppArmor?
- AppArmor ("Application Armor") is a Linux kernel security module that allows the system administrator to restrict programs' capabilities with per-program profiles.
- (read more: https://en.wikipedia.org/wiki/AppArmor)

What is SSH?
- SSH, also known as Secure Shell or Secure Socket Shell, is a network protocol that gives users, particularly system administrators, a secure way to access a computer over an unsecured network. It uses encryption techniques so that all communication between clients and hosts is done in encrypted form. User on Mac or Linux can use SSH the terminal to work on their server via SSH.
- (read more: https://searchsecurity.techtarget.com/definition/Secure-Shell)

What is the **TTY**?
- teletypewriter or teletype that enable the machine to allow messages to be typed, encoded, sent, received, decoded, and printed.

What is LVM?
- Logical Volume Manager, it allows us to easily manipulate the partitions or logical volume on a storage device.

What is UFW?
- UFW is a interface to modify the firewall of the device without compromising security. You use it to configure which ports to allow connections to and which ports to close. This is useful in conjunction with SSH, can set a specific port for it to work with.

What is Cron?
- Cron or cron job is a command line utility to schedule commands or scripts to happen at specific intervals or a specific time each day. Useful if you want to set your server to restart at a specific time each day.


How to modify **hostname**?
- Edit the file, `/etc/hostname`
- Edit the file, `/etc/hosts`
- Run command: `/etc/init.d/hostnamd.sh start`

How to create and remove a new **user**?
- `sudo adduser <user>`
- `sudo userdel -r <user>`

```bash
$ sudo adduser username         # Create new user (yes (no))
$ sudo chage -l username        # Verify password expire info for new user
$ sudo adduser username sudo    # Assign new user to sudo group
$ sudo adduser username user42  # Assign new user to user42 group
```

How to create remove a new **group**?
- `sudo addgroup <group>`
- `sudo groupdel <group>`

How to add or remove user to a group?
- `sudo usermod -aG <group> <user>`
- `sudo deluser <user> <group>`

How to open and close a port?
- to check the UFW ruls, `sudo ufw status numbered`
- `sudo ufw allow 8080`
- `sudo ufw deny 8080`
- `sudo ufw delete <numbered rule>`

## Part two: What to check?
```bash
$ lsblk                             # Check partitions
$ sudo aa-status                    # AppArmor status
$ getent group sudo                 # sudo group users
$ getent group user42               # user42 group users
$ sudo service ssh status           # ssh status, yep
$ sudo ufw status                   # ufw status
$ ssh username@ipadress -p 4242     # connect to VM from your host (physical) machine via SSH
$ nano /etc/sudoers.d/<filename>    # yes, sudo config file. You can $ ls /etc/sudoers.d first
$ nano /etc/login.defs              # password expire policy
$ nano /etc/pam.d/common-password   # password policy
$ sudo crontab -l                   # cron schedule
```

---

etc
```bash
$ sudo ufw status
$ sudo systemctl status ssh
$ getent group sudo
$ getent group user42
$ sudo adduser <username>
$ sudo groupadd <groupname>
$ sudo usermod -aG <groupname> <username>
$ sudo chage -l <username>  # check password expire rules
$ hostnamectl
$ hostnamectl <set-hostname> <new_hostname>     # to change the current hostname, and Restart your Virtual Machine.
$ sudo nano /etc/hosts      # change current hostname to new hostname
$ lsblk     # to display the partitions
$ dpkg -l | grep sudo   # to show that sudo is installed
$ sudo ufw status numbered
$ sudo ufw allow <port>
$ sudo ufw delete <rule number>
$ ssh <your_user_id>@<127.0.0.1> -p 4242    # do this in terminal to show that SSH to port 4242 is working
```
