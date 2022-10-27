# Python C Extension

```bash
cmake -B out
cmake --build out --config Release
```

> **NOTE**
>
> The Python extension cannot link statically to the Python library. Otherwise, when the Python interperter loaded the extension, it would crash. We must ensure Python has been installed successfully.
>
> For example, on Windows, Python 3.10 is installed under `%USERPROFILE%/AppData\Local\Programs\Python\Python310` by default. We can found `python3.lib` under the `libs` subdirectory.

Then, copy the `xyz.pyd` from `out/Release` directory to the `Lib` subdirectory of the Python installation path.

After that, you can test the C function in Python CLI like:

```python
>>> import xyz
>>> x = xyz.f(11)
11.00 + 100.00 = 111.00
>>> x
111.0
```
