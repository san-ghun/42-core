## Configure cron

```bash
root@hostname:~# sudo crontab -e
```

```bash
*/10 * * * * sh /path/to/file/monitoring.sh
```

```bash
root@hostname:~# systemctl enable cron.service
root@hostname:~# reboot
```