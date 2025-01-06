uniform float u_time;

void main() {

	vec4 color = vec4(0.0, 0.0, 0.0, u_time);

	gl_FragColor = color;
}