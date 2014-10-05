""" Reverses the string put in. """

def reverse_str(s)
  length = s.length
  out = []
  while length > 0 do
    out.push( s[length-1])
    length -= 1
  end
  return out.join('')
end

puts(reverse_str('abc') === 'cba')
