#version 330 core

out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform int tick;
uniform vec2 res;
uniform float time;
uniform sampler2D ourTexture;


void main()
{
    vec2 uv = gl_FragCoord.xy / res.xy;
    vec3 col = 0.5 + 0.5 * cos(time + uv.xyx + vec3(0, 2, 4));
    // vec3 noise = noise3(col.xyz);
    // float noise = (gl_FragCoord);

    FragColor = texture(ourTexture, TexCoord) * vec4(col, 1.0);//vec4(uv.x, uv.x, uv.y, 1.0);
}
