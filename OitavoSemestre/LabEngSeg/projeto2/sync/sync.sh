#!/bin/bash

# Sincronizar a pasta /sync-data com o servidor vulnerável
rsync -avz /sync-data/ root@vulnerable-php-site:/var/www/html