import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
from PIL import Image
# Função para carregar a textura

scale_factor = 1.0
translation = [0.0, 0.0]
rotation = [0.0, 0.0]
use_texture = True


def load_texture(texture_path, is_3d=False):
    texture = Image.open(texture_path)
    texture_data = texture.tobytes("raw", "RGB", 0, -1)
    width, height = texture.size

    depth = 0

    texture_id = glGenTextures(1)
    glBindTexture(GL_TEXTURE_3D if is_3d else GL_TEXTURE_2D, texture_id)
    glTexParameteri(GL_TEXTURE_3D if is_3d else GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
    glTexParameteri(GL_TEXTURE_3D if is_3d else GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
    
    if is_3d:
        glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB, width, height, depth, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data)
    else:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data)

    return texture_id


# Função para carregar o objeto .obj
def load_obj(obj_path):
    vertices = []
    textures = []
    faces = []

    with open(obj_path, 'r') as obj_file:
        for line in obj_file:
            if line.startswith('v '):
                vertices.append(list(map(float, line.split()[1:])))
            elif line.startswith('vt '):
                textures.append(list(map(float, line.split()[1:])))
            elif line.startswith('f '):
                face = [list(map(int, vertex.split('/'))) for vertex in line.split()[1:]]
                faces.append(face)

    return vertices, textures, faces


def draw_obj(vertices, faces):
    glPushMatrix()

    glTranslatef(translation[0], translation[1], 0.0)
    glScalef(scale_factor, scale_factor, scale_factor)
    glRotatef(rotation[0], 1, 0, 0)
    glRotatef(rotation[1], 0, 1, 0)

    glBegin(GL_TRIANGLES)
    for face in faces:
        for vertex in face:
            vertex_index = vertex[0] - 1
            x, y, z = vertices[vertex_index]
            glVertex(x, y, z)
    glEnd()

    glPopMatrix()



def center_object(vertices):
    min_x = min(vertices, key=lambda v: v[0])[0]
    max_x = max(vertices, key=lambda v: v[0])[0]
    min_y = min(vertices, key=lambda v: v[1])[1]
    max_y = max(vertices, key=lambda v: v[1])[1]

    object_width = max_x - min_x
    object_height = max_y - min_y

    global scale_factor
    scale_factor = 2.0 / max(object_width, object_height)

def main():
    global scale_factor
    global use_texture

    pygame.init()
    display = (800, 600)
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)
    glTranslatef(0.0, 0.0, -5)

    obj_path = 'TRTL_BOX/TRTL_BOX.obj'
    texture_path = 'TRTL_BOX/TRTL_BOX.jpg'

    vertices, textures, faces = load_obj(obj_path)
    texture_id = load_texture(texture_path)
    # Centralizar automaticamente o objeto
    center_object(vertices)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_z:
                    scale_factor *= 1.1
                elif event.key == pygame.K_x:
                    scale_factor /= 1.1
                elif event.key == pygame.K_a:
                    translation[0] -= 0.1
                    translation[0] = max(translation[0], -1.0)
                elif event.key == pygame.K_d:
                    translation[0] += 0.1
                    translation[0] = min(translation[0], 1.0)
                elif event.key == pygame.K_w:
                    translation[1] += 0.1
                    translation[1] = min(translation[1], 1.0)
                elif event.key == pygame.K_s:
                    translation[1] -= 0.1
                    translation[1] = max(translation[1], -1.0)
                elif event.key == pygame.K_LEFT:
                    rotation[1] -= 5
                elif event.key == pygame.K_RIGHT:
                    rotation[1] += 5
                elif event.key == pygame.K_UP:
                    rotation[0] -= 5
                elif event.key == pygame.K_DOWN:
                    rotation[0] += 5
                elif event.key == pygame.K_p:
                    use_texture = not use_texture

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        #glEnable(GL_TEXTURE_2D)
        draw_obj(vertices, faces)
        pygame.display.flip()
        pygame.time.wait(10)

if __name__ == "__main__":
    main()