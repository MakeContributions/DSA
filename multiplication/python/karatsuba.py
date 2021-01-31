def equalize_strings(x, y):
  n = len(x)
  m = len(y)
  zeros = abs(n - m) * '0'
  if n > m:
    y = zeros + y
  elif m > n:
    x = zeros + x
  return x, y, len(x)

def sum(x, y):
  x, y, size = equalize_strings(x, y)
  carry = 0
  result = ''
  for i in range(1, size+1):
    # print(i)
    dgt1 = int(x[size - i])
    dgt2 = int(y[size - i])
    dgt3 = (dgt1 + dgt2 + carry) % 10
    result = str(dgt3) + result
    carry = int((dgt1 + dgt2 + carry) / 10)
    # print(dgt1, dgt2, dgt3, result, carry)

  if carry:
    result = '1' + result
  return result

def subtract(x, y):
  x, y, size = equalize_strings(x, y)
  carry = 0
  result = ""
  for i in range(size):
    if y[i] < x[i]:
      break
    elif x[i] < y[i]:
      tmp = x
      x = y
      y = tmp
      break

  for i in range(1, size+1):
    dgt1 = int(x[size - i])
    dgt2 = int(y[size - i])
    dgt3 = dgt1 - dgt2 - carry
    if dgt3 < 0:
      dgt3 += 10
      carry = 1
    else:
      carry = 0
    result = str(dgt3) + result
  return result

def kmul(x ,y):
  x, y, size = equalize_strings(x, y)
  if size == 1:
    return str(int(x) * int(y))
  mid = int(size / 2)
  a = x[:mid]
  b = x[mid:]
  c = y[:mid]
  d = y[mid:]
  ac = kmul(a, c)
  bd = kmul(b, d)
  ab_cd = kmul(sum(a, b), sum(c, d))
  ad_bc = subtract(ab_cd, sum(ac, bd))
  zeros = "0" * (size - mid)

  result = sum(ac + 2 * zeros, ad_bc + zeros)
  result = sum(result, bd)
  result = result.lstrip('0')
  return result

x = "134231412"
y = "141324"
print(kmul(x, y))
