//varying vec3 fcolor;

varying vec2 fTexture;
uniform sampler2D texSampler;

uniform bool hasTexture;

void main() {
	gl_FragColor = vec4(1, 1, 1, 1);
}
