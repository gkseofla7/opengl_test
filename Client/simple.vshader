#version 330 core
layout(location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout(location = 1) in vec3 aColor; // the color variable has attribute position 1


layout(std140) uniform transform
{
    vec4 offset;
};
//uniform vec4 transform;

out vec3 ourColor; // output a color to the fragment shader

void main()
{
    gl_Position = vec4(aPos, 1.0) + offset;
    ourColor = aColor; // set ourColor to the input color we got from the vertex data
}