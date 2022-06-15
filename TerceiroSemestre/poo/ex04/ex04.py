# Raphael Leveque 12542522
import os
import pandas as pd
import glob
import csv

class Grupos:
    def __init__(self) -> None:
        self.grupo = []
        self.tamanhoIncorreto = []
        self.turma1 = []
        self.turma2 = []
        self.formatacaoInadequada = []
        self.emMaisTurmas = []

    def turmas(self, alunosDoGrupo: list, tipoDoGrupo):
        if tipoDoGrupo == 1:
            self.turma1.append(alunosDoGrupo)
        elif tipoDoGrupo == 2:
            self.turma2.append(alunosDoGrupo)

    def tamanho_incorreto(self, alunosDoGrupo: list):
        self.tamanhoIncorreto.append(alunosDoGrupo)

    def formatacao_inadequada(self, alunosDoGrupo: list):
        self.formatacaoInadequada.append(alunosDoGrupo)

    def em_mais_turmas(self, alunosDoGrupo: list):
        self.emMaisTurmas.append(alunosDoGrupo)


def divisaoEmGrupos(arquivos, grupos: Grupos, turma1, turma2):
    for f in arquivos:
        nomes = str(f).split('/')
        dataframe = pd.read_csv(f, encoding='latin-1', names=['numero_usp', 'nome'])
        nusp_t1 = dataframe['numero_usp'].isin(pd.to_numeric(turma1['numero_usp'], errors='coerce')).all()
        nusp_t2 = dataframe['numero_usp'].isin(pd.to_numeric(turma2['numero_usp'], errors='coerce')).all()

        if(len(dataframe) == 1):
            opener = open(f, 'r', encoding='latin-1')
            comma = csv.reader(opener)
            items = []
            for row in comma:
                items.append(row)
            if(len(items[0]) > 2):
                nusp_t1 = False
                nusp_t2 = False

        if(nusp_t1):
            grupos.turmas(nomes[9], 1)
            turma1 = turma1[(turma1['numero_usp'].isin(dataframe['numero_usp'])) == False]
        if(nusp_t2):
            grupos.turmas(nomes[9], 2)
            turma2 = turma2[(turma2['numero_usp'].isin(dataframe['numero_usp'])) == False]
        if((not nusp_t1) and (not nusp_t2)):
            grupos.formatacao_inadequada(nomes[9])
        if(nusp_t1 and nusp_t2):
            grupos.em_mais_turmas(nomes[9])
        if((len(dataframe)) != 4):
            grupos.tamanho_incorreto(nomes[9])

    print("Alunos sem grupo ou arquivo inconsistente: ")
    if(len(turma1) > 0):
        print(turma1)
    if(len(turma2) > 0):
        print(turma2)
    else:
        print("Nenhum aluno está sem grupo!")


def printandoGrupos(grupos: Grupos, turma):
    if turma == 1:
        gen = (i for i in grupos.turma1)
    elif turma == 2:
        gen = (i for i in grupos.turma2)
    else:
        gen = (i for i in grupos.emMaisTurmas)

    for i in gen:
        dataframe = pd.read_csv('Grupos/' + i, encoding='latin-1', names=['numero_usp', 'nome'])
        dataframe = dataframe.values.tolist()
        if i in grupos.tamanhoIncorreto:
            print()
            print("Grupo com número invalido de participantes:")
        print(dataframe)

        print()


def main():
    path = os.getcwd() + "/Grupos/"
    arquivos = glob.glob(path + "/Grupos/*.csv")

    turma1 = pd.read_csv("ListadeApoioaoDocente-SSC01032022101.csv", encoding='latin-1', names=['numero_usp', 'nome'])
    turma2 = pd.read_csv("ListadeApoioaoDocente-SSC01032022102.csv", encoding='latin-1', names=['numero_usp', 'nome'])
    grupos = Grupos()

    divisaoEmGrupos(arquivos, grupos, turma1, turma2)

    print("Grupos da turma 1: ")
    printandoGrupos(grupos, 1)
    print("Grupos da turma 2: ")
    printandoGrupos(grupos, 2)
    print("Arquivos inválidos ou com formatação inadequada: ")
    for i in grupos.formatacaoInadequada:
        print(i)
    print()
    print("Grupos com membros nas duas turmas: ")
    printandoGrupos(grupos, 3)
    for i in arquivos:
        i.close()


if __name__ == "__main__":
    main()
