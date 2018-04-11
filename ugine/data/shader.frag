//varying vec3 fcolor;

/*varying vec2 fTexture;
uniform sampler2D texSampler;

uniform bool hasTexture;

void main() {
	if (!hasTexture)
	{
		gl_FragColor = vec4(1, 1, 1, 1);
	}
	else
	{
		gl_FragColor = texture2D(textSampler, fTexture);
	}
}*/

varying vec2 fTexture;
uniform bool isTexturized;
uniform sampler2D texSampler;

void main() {
	if (!isTexturized) {
		gl_FragColor = vec4(1, 1, 1, 1);
	} else {
		gl_FragColor = texture2D(texSampler, fTexture);
	}

}
