flag = [38,
  51,
  36,
  56,
  58,
  112,
  30,
  38,
  113,
  53,
  30,
  50,
  52,
  49,
  114,
  51,
  30,
  37,
  52,
  49,
  114,
  51,
  30,
  45,
  52,
  34,
  42,
  56,
  30,
  46,
  51,
  30,
  112,
  44,
  30,
  43,
  52,
  50,
  53,
  30,
  49,
  51,
  113,
  30,
  51,
  114,
  55,
  36,
  51,
  50,
  36,
  51,
  60,
  65]
ans = ""
for i in flag:
    ans += chr(i^65)
print(ans)