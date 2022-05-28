
class FigurasGeometricas:
    def __init__(self, figura) -> None:
        self.figura = figura


class Circulo(FigurasGeometricas):
    PI = 3.1415
    def __init__(self, raio) -> None:
        self.raio = raio
        super().__init__("Círculo")

    def calcular_area(self):
        return Circulo.PI * (self.raio ** 2)

    def calcular_perimetro(self):
        return 2 * Circulo.PI * self.raio


class Quadrado(FigurasGeometricas):
    def __init__(self, lado) -> None:
        self.lado = lado
        super().__init__("Quadrado")

    def calcular_area(self):
        return self.lado ** 2

    def calcular_perimetro(self):
        return 4 * self.lado


class Retangulo(FigurasGeometricas):
    def __init__(self, lado1, lado2) -> None:
        self.lado1 = lado1
        self.lado2 = lado2
        super().__init__("Retângulo")

    def calcular_area(self):
        return self.lado1 * self.lado2

    def calcular_perimetro(self):
        return 2 * (self.lado1 + self.lado2)