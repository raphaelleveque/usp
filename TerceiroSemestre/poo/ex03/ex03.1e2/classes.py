

class Pessoa:
    def __init__(self, nome, endereco, email, id) -> None:
        self.nome = nome
        self.endereco = endereco
        self.email = email
        self.id = id
        self.pessoaFisica = False
        self.pessoaJuridica = False

    def __str__(self) -> str:
        return f"Nome: {self.nome}\nEndereço: {self.endereco}\nEmail: {self.email}\n"
        
  



class PessoaFisica(Pessoa):
    contador = 0
    def __init__(self, cpf, data_nascimento, estado_civil , nome, endereco, email) -> None:
        self.data = data_nascimento
        self.estado_civil = estado_civil
        self.pessoaFisica = True
        PessoaFisica.contador += 1
        super().__init__(nome, endereco, email, cpf)
    
    def __del__(self):
        PessoaFisica.contador -= 1

    def __str__(self) -> str:
        return super().__str__() + f"CPF: {self.id}\nData de nasacimento: {self.data}\nEstado Civil: {self.estado_civil}\n\n"


class PessoaJuridica(Pessoa):
    contador = 0
    def __init__(self, cnpj, inscricao, razao_social, nome, endereco, email) -> None:
        self.inscricao = inscricao
        self.razao_social = razao_social
        self.pessoaJuridica = True
        PessoaJuridica.contador += 1
        super().__init__(nome, endereco, email, cnpj)
    
    def __del__(self):
        PessoaJuridica.contador -= 1
    
    def __str__(self) -> str:
        return super().__str__() + f"CNPJ: {self.id}\nInscrição Estadual: {self.inscricao}\nRazão Social: {self.razao_social}\n\n"
        
