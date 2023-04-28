# Born2beRoot

### Summary

- Keywords: `system administration` `virtual machine` `virtualization` `VirtualBox` `operating system` `Debian` `cron` 

0. Environment
    - base machine: Linux Ubuntu
    - virtual machine program: Oracle VM VirtualBox
    - virtual machine type: Linux Debian (64-bit)

1. Objective 
    - Create a virtual machine with `VirtualBox` under specific instructions.
    - Set up an operating system while implementing strict rules.
    - Understand how **virtualization** work.
    - Learn how install and set up OS properly.

2. List of todos 
    - Mandatory
        - **Operating System** : Choose an operating system to install,
        - **LVM** : Create at least 2 encrypted partition using `LVM`.
        - **SSH** : Enable `SSH` service running on port 4242 only.
            - For security reasons, must not be possible to connect using `SSH` as root.
        - **UFW** : Configure the OS with the `UFW` firewall and leave only port 4242 open.
        - **hostname** : The `hostname` of the virtual machine must be login ending with "42" (e.g., sanghupa42).
            - Have to know how to modify this hostname.
        - **User** : In addition to the `root` user, a user with login as username has to be present.
        - **Group** : This user login has to belong to the `user42` and `sudo` group.
        - **Password Policy** : Implement a strong password policy.
        - **sudo** : Install and configure `sudo` under specific strict rules.
        - **cron** : Create a script called `monitoring.sh` developed in `bash`. Cron the execution of the file to display some information on all terminals every 10 minutes.No error must be visible.

    - Bonus
        - **Advanced Partitions** : Set up advanced partitions as specified in requirement.
        - **WordPress** : Set up a functional WordPress website with the following services: `lighttpd`, `MariaDB`, and `PHP`.
        - **A Service** : Set up a service of own choice that is useful (exclude NGINX and Apache2)
