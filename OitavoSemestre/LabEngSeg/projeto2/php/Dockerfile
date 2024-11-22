# Usando a imagem oficial do PHP 5.6 com Apache
FROM php:5.6-apache

# Ajustar os repositórios do Debian para o arquivo legado
RUN sed -i 's/deb.debian.org\/debian/archive.debian.org\/debian/g' /etc/apt/sources.list && \
    sed -i 's|security.debian.org|archive.debian.org|g' /etc/apt/sources.list && \
    sed -i '/stretch-updates/d' /etc/apt/sources.list && \
    echo "Acquire::Check-Valid-Until false;" >> /etc/apt/apt.conf.d/99no-check-valid-until && \
    apt-get update && \
    apt-get install -y \
        gnupg2 \
        openssh-server && \
    apt-get clean

# Define o diretório de trabalho padrão
WORKDIR /var/www/html

# Copia os arquivos do projeto para o container
COPY . /var/www/html

# Ajustar permissões (se necessário)
RUN chown -R www-data:www-data /var/www/html && \
    chmod -R 755 /var/www/html

# Expor a porta padrão do Apache
EXPOSE 80
