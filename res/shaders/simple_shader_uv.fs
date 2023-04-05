#version 330 core
out vec4 FragColor;

uniform vec2 res;

void main()
{
    vec2 uv = gl_FragCoord.xy / res.xy;
    float uv_sum = ((uv.x - uv.y) + 1) / 2;

    FragColor = vec4(uv.x, uv_sum, uv.y, 1.0);
}