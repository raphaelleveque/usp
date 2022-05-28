from classes import *

def inserir_ordenado(agenda, pessoa):
    for i in range(len(agenda)):
        if agenda[i].id > pessoa.id:
            agenda.insert(i, pessoa)
            return
    agenda.append(pessoa)


def operacao1(agenda, tipo_pessoa):
    if (tipo_pessoa == 1):
        nome = input("\nDigite o nome do contato: ")
        endereco = input("Digite o endereco do contato: ")
        email = input("Digite o email do contato: ")
        cpf = int(input("Digite o CPF (só os números): "))
        data_nascimento = input("Digite a data de nascimento no formato DD/MM/AAAA: ")
        estado_civil = input("Digite o Estado Civil: ")

        pessoa = PessoaFisica(cpf, data_nascimento, estado_civil, nome, endereco, email)
        inserir_ordenado(agenda, pessoa)
    else:
        nome = input("\nDigite o nome do contato: ")
        endereco = input("Digite o endereco do contato: ")
        email = input("Digite o email do contato: ")
        cnpj = int(input("Digite o CNPJ (só os números): "))
        inscricao = input("Digite a inscrição estadual: ")
        razao_social = input("Digite a razão social: ")

        pessoa = PessoaJuridica(cnpj, inscricao, razao_social, nome, endereco, email)
        inserir_ordenado(agenda, pessoa)
    return agenda


def busca_binaria(agenda, id, esq, dir):
    if dir <= esq:
        return -1
    meio = (esq + dir) // 2
    if agenda[meio].id > id:
        return busca_binaria(agenda, id, esq, meio - 1)
    elif agenda[meio].id < id:
        return busca_binaria(agenda, id, meio + 1, dir)
    else:
        return meio


def operacao2(agenda, tipo_pessoa):
    if tipo_pessoa == 1:
        id = int(input("Digite o CPF da pessoa que deseja remover de sua lista de contatos: "))
    else:
        id = int(input("Digite o CNPJ da pessoa que deseja remover de sua lista de contatos: "))
    
    resultado = busca_binaria(agenda, id, 0, len(agenda))

    if resultado == -1:
        print("Contato a ser removido não encontrado! ")
    else:
        print("Contato excluído: ")
        print(agenda[resultado])
        del(agenda[resultado])


def operacao3(agenda_pf, agenda_pj):
    print("\n\n")
    for i in range(len(agenda_pf)):
        print(agenda_pf[i])
    for i in range(len(agenda_pj)):
        print(agenda_pj[i])


def busca_por_nome(agenda, nome):
    i = 0
    while i < len(agenda) and agenda[i].nome != nome:
        i += 1
    if i == len(agenda):
        print("Pessoa não encontrada")
    else:
        print(agenda[i])


def operacao4(agenda):
    nome = input("Digite o nome da pessoa a ser procurada: ")
    print("\n\n")
    busca_por_nome(agenda, nome)


def operacao5(agenda, id):
    resultado = busca_binaria(agenda, id, 0, len(agenda))

    if resultado == -1:
        print("\nContato a ser removido não encontrado! ")
    else:
        print(agenda[resultado])




