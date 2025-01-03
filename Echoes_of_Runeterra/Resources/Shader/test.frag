uniform float u_time;

void main() {

	vec4 color = vec4(0.0, 0.0, 0.0, u_time);

	gl_FragColor = color;

  //  vec4 color = texture2D(u_texture, gl_TexCoord[0].xy);
  //
  //  // Calculate brightness based on the normalized time
  //  float brightness = 0.0;
  //  if (u_time < 6.0) {
  //      brightness = 0.2 + 0.1 * (u_time / 6.0); // Night to dawn
  //  } else if (u_time < 18.0) {
  //      brightness = 0.3 + 0.7 * ((u_time - 6.0) / 12.0); // Dawn to day
  //  } else {
  //      brightness = 0.3 + 0.1 * ((24.0 - u_time) / 6.0); // Day to night
  //  }
  //
  //  // Apply brightness to the color
  //  color.rgb *= brightness;
  //
  //  // Optional: Add a tint for night or dawn
  //  if (u_time < 6.0 || u_time > 18.0) {
  //      color.rgb += vec3(0.0, 0.0, 0.1) * (1.0 - brightness); // Night tint
  //  } else if (u_time < 8.0 || u_time > 16.0) {
  //      color.rgb += vec3(0.1, 0.05, 0.0) * (1.0 - brightness); // Dawn/dusk tint
  //  }
  //
  //  gl_FragColor = color;
}