const h1 = document.querySelector('h1');
const P1 = document.querySelector('#P1');
h1.innerText = "Hello world";
h1.style.cssText = "color: blue";
P1.innerHTML = "<b>asjfgiasg</b>";
const novoEl = document.createElement('p');
novoEl.innerText = 'Novo elemento'
h1.appendChild(novoEl);