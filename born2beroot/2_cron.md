## Configure cron

```bash
root@hostname:~# sudo crontab -e
```

```bash
*/10 * * * * sh /path/to/file/monitoring.sh
*/1 * * * * sh /path/to/file/monitoring.sh      # in every minutes
```

```bash
root@hostname:~# systemctl enable cron.service
root@hostname:~# reboot
```