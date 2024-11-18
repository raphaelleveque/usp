FROM ubuntu:latest

# Atualizar o sistema e instalar rsync, cron e ssh-client
RUN apt-get update && apt-get install -y \
    rsync \
    cron \
    openssh-client

# Copiar o script de sincronização
COPY sync.sh /root/sync.sh
RUN chmod +x /root/sync.sh

# Configurar cron job para rodar a cada 15 minutos
RUN (crontab -l ; echo "*/15 * * * * /root/sync.sh") | crontab

# Rodar o cron em foreground
CMD cron -f
