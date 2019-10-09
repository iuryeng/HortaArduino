
## Fundamentos de programação em C

### Variavel

<details>
<summary>Veja o conteúdo</summary>

* [`ary`](#ary)


</details>

### Array

<details>
<summary>Veja o conteúdo</summary>

* [`all`](#all)


</details>

### ary

Creates a function that accepts up to `n` arguments, ignoring any additional arguments.

Call the provided function, `fn`, with up to `n` arguments, using `Array.prototype.slice(0,n)` and the spread operator (`...`).

```js
const ary = (fn, n) => (...args) => fn(...args.slice(0, n));
```

<details>
<summary>Examples</summary>

```js
const firstTwoMax = ary(Math.max, 2);
[[2, 6, 'a'], [6, 4, 8], [10]].map(x => firstTwoMax(...x)); // [6, 6, 10]
```
</details>

<br>[⬆ Back to top](#contents)
