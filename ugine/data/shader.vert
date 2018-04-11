//varying vec3 fcolor;

attribute vec3 vpos;

uniform mat4 mvpMatrix;

void main() {
	gl_Position = mvpMatrix * vec4(vpos, 1);
	
	//fcolor = vec3(1, 1, 1);
}