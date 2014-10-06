# Takes a string and returns the Run-length encoding (RLE) compressed version.
# For example something like: 1111231114 will be: 4112133114, WWWYYXWW will be: 3W2Y1X2W

def rle(s)
    counts = []

    cur_char = ''
    cur_char_count = 0
    out = ''

    s.each_char do |c|
        if cur_char == ''
            cur_char = c
            cur_char_count = 1

        elsif cur_char == c
            cur_char_count += 1

        elsif cur_char != c
            counts.push('%s%s' %  [cur_char_count, cur_char])
            cur_char = c
            cur_char_count = 1
        end
    end

    # Add remaining.
    counts.push('%s%s' %  [cur_char_count, cur_char])

    out = counts.join('')

    return out

end


puts( rle('1111234111')  == '4112131431' )
puts( rle('1112') == '3112')
puts( rle('WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW')  == '12W1B12W3B24W1B14W')
puts( rle('TITTUSS') == '1T1I2T1U2S')
