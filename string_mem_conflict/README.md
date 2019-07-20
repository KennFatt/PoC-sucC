# PoC: C String memory conflict
## Based on how was the variable being declared

**DISCLAIMER**
Im not a master with C language, Im interest with this memory problem. I love how we can control and maintain memory effectively in C.
Please someone explain this one to me by [Email](mailto:kennanfattahillah@gmail.com?subject=Github%20Contact) or DM me on [Twitter](https://twitter.com/KennanFattah).

So this is a Proof of Concept that case 'b' has a conflict with 'c'.
This is not collided or merged the memory address thing. What actually going on here is 'c' memory address also known on 'b'.

```c
char b[] = "letter"; // the size would depends on its length, which is 7.
char c[7] = {'l', 'e', 't', 't', 'e', 'r'}; // include null terminator.
```

**NOTE**  
_These memory footprints taken after program compiled and run it by `./main`._

**Memory footprint**

* Case: 'b'
This is the expected and proper memory footprint of 'b'.
```
[b#0x7ffda0e5c6fa] index(0), value(l), decimal(108)
[b#0x7ffda0e5c6fb] index(1), value(e), decimal(101)
[b#0x7ffda0e5c6fc] index(2), value(t), decimal(116)
[b#0x7ffda0e5c6fd] index(3), value(t), decimal(116)
[b#0x7ffda0e5c6fe] index(4), value(e), decimal(101)
[b#0x7ffda0e5c6ff] index(5), value(r), decimal(114)
[b#0x7ffda0e5c700] index(6), value(), decimal(0)
```
Unfortunately, this is what happend:
```
[b#0x7ffda0e5c6fa] index(0), value(l), decimal(108)
[b#0x7ffda0e5c6fb] index(1), value(e), decimal(101)
[b#0x7ffda0e5c6fc] index(2), value(t), decimal(116)
[b#0x7ffda0e5c6fd] index(3), value(t), decimal(116)
[b#0x7ffda0e5c6fe] index(4), value(e), decimal(101)
[b#0x7ffda0e5c6ff] index(5), value(r), decimal(114)
[b#0x7ffda0e5c700] index(6), value(), decimal(0) -- These bytes should end here.
[b#0x7ffda0e5c701] index(7), value(l), decimal(108) -- Where does it come form?
[b#0x7ffda0e5c702] index(8), value(e), decimal(101)
[b#0x7ffda0e5c703] index(9), value(t), decimal(116)
[b#0x7ffda0e5c704] index(10), value(t), decimal(116)
[b#0x7ffda0e5c705] index(11), value(e), decimal(101)
[b#0x7ffda0e5c706] index(12), value(r), decimal(114)
[b#0x7ffda0e5c707] index(13), value(), decimal(0) -- Fact is, this is null terminator of case 'c', the next variable.
[b#0x7ffda0e5c708] index(14), value(), decimal(0) -- Have no idea with the last one.
```

* Case: 'c'
```
[c#0x7ffda0e5c701] index(0), value(l), decimal(108) -- Okay, I've told you before.
[c#0x7ffda0e5c702] index(1), value(e), decimal(101)
[c#0x7ffda0e5c703] index(2), value(t), decimal(116)
[c#0x7ffda0e5c704] index(3), value(t), decimal(116)
[c#0x7ffda0e5c705] index(4), value(e), decimal(101)
[c#0x7ffda0e5c706] index(5), value(r), decimal(114)
[c#0x7ffda0e5c707] index(6), value(), decimal(0)
[c#0x7ffda0e5c708] index(7), value(), decimal(0)
```

* Full Log (with my comments):
```
[a#0x562a82d68046] index(0), value(l), decimal(108)
[a#0x562a82d68047] index(1), value(e), decimal(101)
[a#0x562a82d68048] index(2), value(t), decimal(116)
[a#0x562a82d68049] index(3), value(t), decimal(116)
[a#0x562a82d6804a] index(4), value(e), decimal(101)
[a#0x562a82d6804b] index(5), value(r), decimal(114)
[a#0x562a82d6804c] index(6), value(), decimal(0)
[a#0x562a82d6804d] index(7), value(), decimal(0) -- Why it's still reconized?
[a#0x562a82d6804e] index(8), value(), decimal(0)
[a#0x562a82d6804f] index(9), value(), decimal(0)
[a#0x562a82d68050] index(10), value(), decimal(1)
[a#0x562a82d68051] index(11), value( decimal(27)
[a#0x562a82d68052] index(12), value(), decimal(3)
[a#0x562a82d68053] index(13), value(;), decimal(59)
[a#0x562a82d68054] index(14), value(D), decimal(68)
[a#0x562a82d68055] index(15), value(), decimal(0)
[a#0x562a82d68056] index(16), value(), decimal(0)
[a#0x562a82d68057] index(17), value(), decimal(0)
[a#0x562a82d68058] index(18), value(), decimal(7)
[a#0x562a82d68059] index(19), value(), decimal(0)
[a#0x562a82d6805a] index(20), value(), decimal(0)
[a#0x562a82d6805b] index(21), value(), decimal(0)
--- END RESULT ---
[b#0x7ffda0e5c6fa] index(0), value(l), decimal(108)
[b#0x7ffda0e5c6fb] index(1), value(e), decimal(101)
[b#0x7ffda0e5c6fc] index(2), value(t), decimal(116)
[b#0x7ffda0e5c6fd] index(3), value(t), decimal(116)
[b#0x7ffda0e5c6fe] index(4), value(e), decimal(101)
[b#0x7ffda0e5c6ff] index(5), value(r), decimal(114)
[b#0x7ffda0e5c700] index(6), value(), decimal(0)
[b#0x7ffda0e5c701] index(7), value(l), decimal(108) -- WHY?!
[b#0x7ffda0e5c702] index(8), value(e), decimal(101)
[b#0x7ffda0e5c703] index(9), value(t), decimal(116)
[b#0x7ffda0e5c704] index(10), value(t), decimal(116)
[b#0x7ffda0e5c705] index(11), value(e), decimal(101)
[b#0x7ffda0e5c706] index(12), value(r), decimal(114)
[b#0x7ffda0e5c707] index(13), value(), decimal(0)
[b#0x7ffda0e5c708] index(14), value(), decimal(0)
--- END RESULT ---
[c#0x7ffda0e5c701] index(0), value(l), decimal(108)
[c#0x7ffda0e5c702] index(1), value(e), decimal(101)
[c#0x7ffda0e5c703] index(2), value(t), decimal(116)
[c#0x7ffda0e5c704] index(3), value(t), decimal(116)
[c#0x7ffda0e5c705] index(4), value(e), decimal(101)
[c#0x7ffda0e5c706] index(5), value(r), decimal(114)
[c#0x7ffda0e5c707] index(6), value(), decimal(0)
[c#0x7ffda0e5c708] index(7), value(), decimal(0) -- I still don't know about this one.
--- END RESULT ---
[d#0x562a82d68046] index(0), value(l), decimal(108)
[d#0x562a82d68047] index(1), value(e), decimal(101)
[d#0x562a82d68048] index(2), value(t), decimal(116)
[d#0x562a82d68049] index(3), value(t), decimal(116)
[d#0x562a82d6804a] index(4), value(e), decimal(101)
[d#0x562a82d6804b] index(5), value(r), decimal(114)
[d#0x562a82d6804c] index(6), value(), decimal(0) -- String literals are using more unknown bytes.
[d#0x562a82d6804d] index(7), value(), decimal(0)
[d#0x562a82d6804e] index(8), value(), decimal(0)
[d#0x562a82d6804f] index(9), value(), decimal(0)
[d#0x562a82d68050] index(10), value(), decimal(1)
[d#0x562a82d68051] index(11), value( decimal(27)
[d#0x562a82d68052] index(12), value(), decimal(3)
[d#0x562a82d68053] index(13), value(;), decimal(59)
[d#0x562a82d68054] index(14), value(D), decimal(68)
[d#0x562a82d68055] index(15), value(), decimal(0)
[d#0x562a82d68056] index(16), value(), decimal(0)
[d#0x562a82d68057] index(17), value(), decimal(0)
[d#0x562a82d68058] index(18), value(), decimal(7)
[d#0x562a82d68059] index(19), value(), decimal(0)
[d#0x562a82d6805a] index(20), value(), decimal(0)
[d#0x562a82d6805b] index(21), value(), decimal(0)
--- END RESULT ---
```
