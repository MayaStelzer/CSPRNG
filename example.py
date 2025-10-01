import secrets

def csprng_bitstring(nbits: int) -> str:
    if nbits <= 0:
        return ""
    value = secrets.randbits(nbits)
    return format(value, '0{}b'.format(nbits))

def csprng_bytestring(nbytes: int) -> str:
    if nbytes <= 0:
        return ""
    value = secrets.token_bytes(nbytes)
    return ''.join(f'{b:08b}' for b in value)

print("10-bit:", csprng_bitstring(10))
print("128-bit:", csprng_bitstring(128))

print("8-byte:", csprng_bytestring(8))
print("16-byte:", csprng_bytestring(16))