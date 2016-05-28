static const char *stock_vertex_xmb_modern =
   "in vec3 VertexCoord;\n"
   "uniform float time;\n"
   "out vec3 fragVertexEc;\n"
   "float iqhash( float n )\n"
   "{\n"
   "  return fract(sin(n)*43758.5453);\n"
   "}\n"
   "float noise( vec3 x )\n"
   "{\n"
   "  vec3 p = floor(x);\n"
   "  vec3 f = fract(x);\n"
   "  f = f*f*(3.0-2.0*f);\n"
   "  float n = p.x + p.y*57.0 + 113.0*p.z;\n"
   "  return mix(mix(mix( iqhash(n+0.0 ), iqhash(n+1.0 ),f.x),\n"
   "  mix( iqhash(n+57.0 ), iqhash(n+58.0 ),f.x),f.y),\n"
   "  mix(mix( iqhash(n+113.0), iqhash(n+114.0),f.x),\n"
   "  mix( iqhash(n+170.0), iqhash(n+171.0),f.x),f.y),f.z);\n"
   "}\n"
   "float xmb_noise2( vec3 x )\n"
   "{\n"
   "  return cos((x.z*1.0)*2.0);"
   "}\n"
   "void main()\n"
   "{\n"
   "  vec3 v = vec3(VertexCoord.x, 0.0, VertexCoord.y);\n"
   "  vec3 v2 = v;\n"
   "  vec3 v3 = v;\n"

   "  v.y = xmb_noise2(v2)/6.0;\n"

   "  v3.x = v3.x + time/5.0;\n"
   "  v3.x = v3.x / 2.0;\n"

   "  v3.z = v3.z + time/10.0;\n"
   "  v3.y = v3.y + time/100.0;\n"

   "  v.z = v.z + noise(v3*7.0)/15.0;\n"
   "  v.y = v.y + noise(v3*7.0)/15.0 + cos(v.x*2.0-time/5.0)/5.0 - 0.3;\n"

   "  gl_Position = vec4(v, 1.0);\n"
   "  fragVertexEc = gl_Position.xyz;\n"
   "}\n";
