## OS Configuration

### Basic Configuration

- Login as root: `su`
- Update & Upgrade: `apt update` and `apt upgrade`
- Install sudo: `apt install sudo`
- Add user to sudo group: `sudo usermod -aG sudo sanghupa`
    - `-a` is a shortcut for --append: It means append the group to the list of groups the user belongs to!
    - `-G` is a shortcut for --groups: It tells usermod that the next argument is a group. Note that you need to use a capital -G here because we don’t want to modify the user’s primary group but the list of supplemental groups the user belongs to.
- To check if your user is in the sudo group: `getent group sudo`

- Logout `root` and login to your user: `su - sanghupa`
    - [Why You Shouldn’t Log Into Your Linux System As Root](https://www.howtogeek.com/124950/htg-explains-why-you-shouldnt-log-into-your-linux-system-as-root/)
- Add group `user42`: `sudo groupadd user42`
- Add user to the group: `sudo usermod -aG user42 sanghupa`
- Install `vim`: `sudo apt install vim`
- Install `net-tools`: `sudo apt install net-tools`

---

### SSH Configuration

- Install `OpenSSH`: `sudo apt install openssh-server`
- Verity ssh service: `sudo systemctl status ssh`
- Get ip: `ip a`
- Add port 4242: 
    - go to `/etc/ssh`
    - run `sudo vim sshd_config`
    - edit `#Port 22` to `Port 4242`
    - edit `PermitRootLogin no`
- Install UFW Firewall: `sudo apt install ufw`
- Activate UFW: `sudo ufw enable`
    - to check: `sudo ufw status`

#### Linux

Go to VirutalBox -> Choose the VM -> Select "Settings" -> Choose "Network" -> "Adapter 1" -> " in Attached to: change to "Bridged Adapter"

- Reboot the machine: `sudo reboot`
- Allow the port 4242 on the Firewall: `sudo ufw allow 4242/tcp`
- Get the ip address:   
    ```bash
    ip a | grep inet | grep 'global dynamic' | cut -d'/' -f1 | awk '{ print $2 }'
    ```

To get remote access through ssh port 4242, run this in your VM:
- `sudo ssh -p 4242 username@your_ip` in my case `sudo ssh -p 4242 sanghupa@10.11.250.161`

- [Open SSH](http://www.openssh.com/)
- [An Introduction to Uncomplicated Firewall (UFW)](https://www.linux.com/training-tutorials/introduction-uncomplicated-firewall-ufw/)

---

### Password Policy

To enforce password complexity I will use `pwquality.conf`: `sudo apt install libpam-pwquality`

Go to `/etc` and run `sudo vim login.defs`

- Search for:
    - `PASS_MAX_DAYS  9999`
    - `PASS_MIN_DAYS   0`
    - `PASS_WARN_AGE   7`
    - and change to
    - `PASS_MAX_DAYS  30`
    - `PASS_MIN_DAYS   2`
    - `PASS_WARN_AGE   7`

Go to `/etc/pam.d` and run `sudo vim common-password` 

- find `password    requisite   pam_pwquality.so retry=3`
    - To set at least one upper-case letter in the pw add `ucredit=-1`
    - To set at least one lower-case letter in the pw add `lcredit=-1`

    - To set at least one digit in the pw add `dcredit=-1`
    - To set the minimum length in the pw add `minlen=10`
    - To set at max consecutive identical chars in the pw add `maxrepeat=3`
    - To check if the password contains the username in some form add `usercheck=0`
    - To set a minimum number of chars that must be different from the old pw add `difok=7`
    - To the root pw comply to this policy add `enforce_for_root`
- Reboot your VM: `sudo reboot`

- [Pam_pwquality](https://linux.die.net/man/8/pam_pwquality)

---

### Sudo Policy

Go to `/etc/sudoers.d` and run `sudo visudo`

> NEVER EDIT THE SUDOERS FILE WITH A NORMAL TEXT EDITOR, ALWAYS USE sudo visudo

- Find the `Defaults` section and add:
    - To enable TTY `Defaults  requiretty`
    - To select the right folder for your log files `Defaults  logfile="/var/log/sudo/sudo.log"`
    - To archive your log inputs and outputs `Defaults log_input, log_output`
    - To set your password retries (It usually comes 3 times as default, but still...) `Defaults   passwd_tries=3`
    - To enable TTY `Defaults   badpass_message="<Your message>"`
    - The security pass probably is already there, but in case it isn't `Defaults   secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"`

- [Linux 101: Introduction to sudo](https://www.linux.com/training-tutorials/linux-101-introduction-sudo/)
