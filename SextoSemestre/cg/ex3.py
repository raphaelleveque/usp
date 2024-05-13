import glm
import numpy as np

# Definindo os vértices do objeto
P1 = glm.vec3(0, 0, 0)
P5 = glm.vec3(0.5, -1, 0)  # Coordenada de P5 que eu tirei olhando para ela

# Matriz de translação para levar P5 para a origem
T1 = glm.translate(glm.mat4(1.0), -P5)

# Matriz de rotação em torno da origem (90 graus em torno do eixo z)
R = glm.rotate(glm.mat4(1.0), glm.radians(90.0), glm.vec3(0, 0, 1))

# Matriz de escala uniforme (redução pela metade)
S = glm.scale(glm.mat4(1.0), glm.vec3(0.5, 0.5, 0.5))

# Calculando a matriz composta
composite_matrix = T1 * R * S

# Aplicando a matriz composta ao vértice P1
transformed_P1 = glm.vec3(composite_matrix * glm.vec4(P1, 1.0))

# Imprimindo a matriz composta final e a coordenada do vértice P1 após as transformações
print("Matriz Composta Final:")
print(np.array(composite_matrix))  # Convertendo para numpy array para imprimir como lista
print("\nCoordenada de P1 após as transformações:")
print(glm.vec3(transformed_P1))  # Imprimindo diretamente a coordenada
