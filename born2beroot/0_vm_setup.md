## VM Setup

### Create VM

* VirtualBox: New
* Name: {Anyname}
* Machine folder: /sgoinfre/goinfre/Perso/\{yourlogin}
* Type: Linux
* Version: Debian 64-bit

1. RAM: 1024MB
2. Create a virtual hard disk now (VDI)
3. Fixed size: 8GB

*If need, get the Debian ISO from [here](https://www.debian.org/download)

---

### Install Debian OS

**Power On your VM and select your OS (Debian)**

1. Select Install (Don't select graphical install it is useless)
2. Language: English
3. Choose **your** area
4. Choose United State (en_US.UTF-8) and American English for keyboard
5. Hostname: {yourlogin}+42 (ex. sanghupa42)
6. Domain: *leave empty*

**Now configure your account and root** 

1. Choose a password for root that feat with subject
    * (you can take an easy password but don't forget to change it)
3. Full Name *leave empty*
4. Username: {yourlogin}
5. Choose a password that feat with subject
    * (you can take an easy password but don't forget to change it)

**Now configure your disk**

1. Partition methode: Guided - Use entire disk and set up encrypted LVM
2. **YES**
3. Select *Separate /home partition* (don't forget)
4. Enter strong passphrase
    * (you can change it later but I recommande to make it hard now)
5. **CONTINUE**
6. Select *Finish partioning and write changes to disk*
7. **YES**
8. Package Manager: No
9. Choose your Country and deb.debian.org
10. HTTP Proxy: Leave empty
11. Participate in the package usage survey: **NO**
12. GRUB YES: sda

---

Use following command to varify the proper configuration of partition.
```bash
> lsblk
```
