scr = None
template_path = None
pad = 20
for i in range(pad):
    for j in range(pad):
        nw = int(w-pad/2+i)
        nh = int(h-pad/2+j)
        sctemp = cv2.resize(scr, (nw, nh))
        val = match(template_path, sctemp)
        if val!=[]:
            print(f"{nw} , {nh}")
