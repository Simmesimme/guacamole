vec3 heat(float v) {
  return (0.5+0.5*smoothstep(0.0, 0.1, v))*vec3(
    smoothstep(0.5, 0.3, v),
    v < 0.3 ? smoothstep(0.0, 0.3, v) : smoothstep(1.0, 0.6, v),
    smoothstep(0.4, 0.6, v)
  );
}
