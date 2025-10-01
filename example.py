import secrets

def csprng_bitstring(nbits: int) -> str:
    if nbits <= 0:
        return ""
    value = secrets.randbits(nbits)
    return format(value, '0{}b'.format(nbits))

print("128-bit:", csprng_bitstring(128))