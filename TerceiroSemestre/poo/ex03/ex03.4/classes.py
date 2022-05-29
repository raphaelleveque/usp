
class Produto:
    def __init__(self, codigo_de_barras, nome) -> None:
        self.codigo_barras = codigo_de_barras
        self.nome = nome
    
    def __str__(self) -> str:
        return f"Nome: {self.nome}\nCodigo de Barras: {self.codigo_barras}"


class Livro(Produto):
    def __init__(self, codigo_de_barras, nome) -> None:
        super().__init__(codigo_de_barras, nome)

class DVD(Produto):
    def __init__(self, codigo_de_barras, nome) -> None:
        super().__init__(codigo_de_barras, nome)

class CD(Produto):
    def __init__(self, codigo_de_barras, nome) -> None:
        super().__init__(codigo_de_barras, nome)

class Loja:
    def __init__(self) -> None:
        self.livros = []
        self.dvds = []
        self.cds = []

    def adicionar_produto(self, tipo_do_produto, codigo_de_barras, quantidade, nome):
        if tipo_do_produto.lower() == "livro":
            for _ in range(quantidade):
                novo_livro = Livro(codigo_de_barras, nome)
                self.livros.append(novo_livro)
        elif tipo_do_produto.lower() == "dvd":
            for _ in range(quantidade):
                novo_dvd = DVD(codigo_de_barras, nome)
                self.dvds.append(novo_dvd)
        elif tipo_do_produto.lower() == "cd":
            for _ in range(quantidade):
                novo_cd = DVD(codigo_de_barras, nome)
                self.cds.append(novo_cd)

    def buscar_produto(self, codigo_de_barras = 0, nome = ""):
        busca_codigo = False
        busca_nome = False
        if codigo_de_barras != 0:
            busca_codigo = True
        else:
            busca_nome = True
        encontrado = False
        if busca_codigo:
            for livro in self.livros:
                if encontrado:
                    break
                if livro.codigo_barras == codigo_de_barras:
                    encontrado = True
                    print(livro)
                    vender = input("Deseja vender este livro s/n? ")
                    if vender == "s":
                        self.livros.remove(livro)

            for dvd in self.dvds:
                if encontrado:
                    break
                if dvd.codigo_barras == codigo_de_barras:
                    encontrado = True
                    print(livro)
                    vender = input("Deseja vender este dvd s/n? ")
                    if vender == "s":
                        self.dvds.remove(dvd)

            for cd in self.cds:
                if encontrado:
                    break
                if cd.codigo_barras == codigo_de_barras:
                    encontrado = True
                    print(livro)
                    vender = input("Deseja vender este cd s/n? ")
                    if vender == "s":
                        self.cds.remove(cd)


        elif busca_nome:
            for livro in self.livros:
                if encontrado:
                    break
                if livro.nome == nome:
                    encontrado = True
                    print(livro)
                    vender = input("Deseja vender este livro s/n? ")
                    if vender == "s":
                        self.livros.remove(livro)

            for dvd in self.dvds:
                if encontrado:
                    break
                if dvd.nome == nome:
                    encontrado = True
                    print(livro)
                    vender = input("Deseja vender este dvd s/n? ")
                    if vender == "s":
                        self.dvds.remove(dvd)

            for cd in self.cds:
                if encontrado:
                    break
                if cd.nome == nome:
                    encontrado = True
                    print(livro)
                    vender = input("Deseja vender este cd s/n? ")
                    if vender == "s":
                        self.cds.remove(cd)

            
    def mostrar_estoque(self):
        print(f"Número de livros no estoque: {len(self.livros)}")
        i = 0
        while i < len(self.livros):
            j = i + 1
            while j < len(self.livros) and self.livros[i].nome == self.livros[j].nome:
                j += 1
            print(self.livros[i])
            print(f"Quantidade: {j - i}\n")
            i = j

        print(f"Número de DVD's no estoque: {len(self.dvds)}")
        i = 0
        while i < len(self.dvds):
            j = i + 1
            while j < len(self.dvds) and self.dvds[i].nome == self.dvds[j].nome:
                j += 1
            print(self.dvds[i])
            print(f"Quantidade: {j - i}\n")
            i = j

        print(f"Número de CD's no estoque: {len(self.cds)}")
        i = 0
        while i < len(self.cds):
            j = i + 1
            while j < len(self.cds) and self.cds[i].nome == self.cds[j].nome:
                j += 1 
            print(self.cds[i])
            print(f"Quantidade: {j - i}\n")
            i = j

