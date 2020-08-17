# MarkDown 本地浏览

## mkdocs

- https://www.mkdocs.org/
- https://markdown-docs-zh.readthedocs.io/zh_CN/latest/
- 环境安装
  - 1.安装python
  - 2.安装mkdosc `pip install mkdocs`
  - 3.运行mkdocs
    - `cd doc/build/mkdocs`
    - `mkdocs serve`

## docfx

- DocFx 是一个dotnetAPI文档生成器，目前支持C#和VB。

## Download DocFx

- [Download](https://github.com/dotnet/docfx/releases)
- [Getting  Started with DocFx](https://dotnet.github.io/docfx/tutorial/docfx_getting_started.html)
- MarkDown数学公式转换需要引入的脚本
```HTML
<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>

<script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
<script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3.0.1/es5/tex-mml-chtml.js"></script>

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>

<script defer src="https://cdn.jsdelivr.net/npm/katex@0.11.1/dist/contrib/auto-render.min.js" integrity="sha384-kWPLUVMOks5AQFrykwIup5lo0m3iMkkHrD0uJ4H5cjeGihAutqP0yW0J6dpFiVkI" crossorigin="anonymous"
      onload='renderMathInElement(document.body, {delimiters: [{ left: "$$", right: "$$", display: true },{ left: "$", right: "$", display: false },{ left: "\\[", right: "\\]", display: true }]});'>
</script>

<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/katex@0.12.0/dist/katex.min.css" integrity="sha384-AfEj0r4/OFrOo5t7NnNe46zW/tFgW6x/bCJG8FqQCEo3+Aro6EYUG4+cU+KJWu/X" crossorigin="anonymous" />
<script defer src="https://cdn.jsdelivr.net/npm/katex@0.12.0/dist/katex.min.js" integrity="sha384-g7c+Jr9ZivxKLnZTDUhnkOnsh30B4H0rpLUpJ4jAIKs4fnJI+sEnkvrMWph2EDg4" crossorigin="anonymous"></script>
<script defer src="https://cdn.jsdelivr.net/npm/katex@0.12.0/dist/contrib/auto-render.min.js" integrity="sha384-mll67QQFJfxn0IYznZYonOWZ644AWYC+Pt2cHqMaRhXVrursRwvLnLaebdGIlYNa" crossorigin="anonymous"
	onload="renderMathInElement(document.body);"></script>
<style>
```