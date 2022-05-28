
class FigurasGeometricas:
    def __init__(self, figura, cor, preenchido) -> None:
        self.figura = figura
        self.cor = cor
        self.preenchido = preenchido

    def __str__(self, area, perimetro) -> str:
        return f"\n\nO {self.figura} possui Area = {area:.1f} e Perímetro = {perimetro:.1f}.\nAlém disso, o {self.figura} {'' if self.preenchido else 'não '}está preenchido{f' com a cor {self.cor}' if self.preenchido else ''}.\n\n"


class Circulo(FigurasGeometricas):
    PI = 3.14
    def __init__(self, raio, cor, preenchido) -> None:
        self.raio = raio
        super().__init__("Círculo", cor, preenchido)

    def calcular_area(self):
        return Circulo.PI * (self.raio ** 2)

    def calcular_perimetro(self):
        return 2 * Circulo.PI * self.raio
    
    def __str__(self) -> str:
        return super().__str__(self.calcular_area(), self.calcular_perimetro())


class Quadrado(FigurasGeometricas):
    def __init__(self, lado, cor, preenchido) -> None:
        self.lado = lado
        super().__init__("Quadrado", cor, preenchido)

    def calcular_area(self):
        return self.lado ** 2

    def calcular_perimetro(self):
        return 4 * self.lado
    
    def __str__(self) -> str:
        return super().__str__(self.calcular_area(), self.calcular_perimetro())


class Retangulo(FigurasGeometricas):
    def __init__(self, lado1, lado2, cor, preenchido) -> None:
        self.lado1 = lado1
        self.lado2 = lado2
        super().__init__("Retângulo", cor, preenchido)

    def calcular_area(self):
        return self.lado1 * self.lado2

    def calcular_perimetro(self):
        return 2 * (self.lado1 + self.lado2)
    
    def __str__(self) -> str:
        return super().__str__(self.calcular_area(), self.calcular_perimetro())