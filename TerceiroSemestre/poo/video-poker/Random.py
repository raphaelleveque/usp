import datetime

class Random(object):
    'Classe para geração de números aleatórios'    
    
    p = 2147483648
    m = 843314861
    a = 453816693

    

    
    def __init__(self, seed = None):
        '''Construtor. Se o parâmetro seed for fornecido, será utilizado como
        semente do gerador de números aleatórios. Se não for, a semente é gerada
        usando o contador de milisegundos do sistema'''
        if not seed :      
            self.xi = self.unix_time_millis() % self.p
        else:
            self.xi = seed
            
    
    def get_rand(self):
        'Método retorna um número aleatório entre [0,1)'
        self.xi = (self.a + self.m * self.xi) % self.p
        d = float(self.xi)
        return d / self.p
        
    def get_int_rand(self,maximo):
        '''Retorna um número aleatório inteiro entre [0,maximo) que é passado 
        como parâmetro'''
        d = self.get_rand() * maximo
        return int(d)
        
    def set_semente(self,k):
        'Permite mudar a semente do gerador, aapós o objeto ter sido criado'
        self.xi = k
    
    def unix_time_millis(self):
        'Função auxiliar que computa o número de milisegundos do sistema'
        dt = datetime.datetime.utcnow()
        epoch = datetime.datetime.utcfromtimestamp(0)
        x = int((dt - epoch).total_seconds() * 1e6)
        return(x)
    

if __name__ == '__main__':
    r = Random(1)
    for i in range(100):
        print(r.get_int_rand(i), end=' ')
    print()
    r = Random()
    for i in range(100):
        print(r.get_int_rand(i), end=' ')
