const binary = document.querySelector('#binary');
const decimal = document.querySelector('#decimal');
const octal = document.querySelector('#octal');
const hexadecimal = document.querySelector('#hexadecimal');

const bases = {
    hex: {
        domElement: hexadecimal,
        typeName: 'hex',
        allowedChars: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'],
        baseNum: 16
    },
    dec: {
        domElement: decimal,
        typeName: 'dec',
        allowedChars: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'],
        baseNum: 10
    },
    oct: {
        domElement: octal,
        typeName: 'oct',
        allowedChars: ['0', '1', '2', '3', '4', '5', '6', '7'],
        baseNum: 8
    },
    bin: {
        domElement: binary,
        typeName: 'bin',
        allowedChars: ['0', '1'],
        baseNum: 2
    },

}

const setAllValues = (value, currentType = '') => {
    if (currentType != 'dec')
        decimal.value = value;
    if (currentType != 'oct')
        octal.value = value;
    if (currentType != 'hex')
        hexadecimal.value = value;
    if (currentType != 'bin')
        binary.value = value;
}

const convertValues = (value, currentType) => {
    if (currentType != 'dec')
        decimal.value = parseInt(value, bases[currentType].baseNum);
    if (currentType != 'oct')
        octal.value = parseInt(decimal.value).toString(8);
    if (currentType != 'hex')
        hexadecimal.value = parseInt(decimal.value).toString(16)
    if (currentType != 'bin')
        binary.value = parseInt(decimal.value).toString(2);
}

const eventFunction = type => {
    return function () {
        let inputValue = bases[type].domElement.value;
        if (!inputValue)
            return setAllValues('');

        inputValue = inputValue.replaceAll(',', '');
        inputValue = inputValue.replaceAll(' ', '');
        inputValue = inputValue.replaceAll('x', '');

        for (let char of inputValue) {
            const currentChar = char.toLowerCase();
            if (!bases[type].allowedChars.includes(currentChar))
                return setAllValues('Invalid input', type);
        }
        convertValues(inputValue, type);
    }
}

binary.addEventListener('input', eventFunction('bin'));
octal.addEventListener('input', eventFunction('oct'));
hexadecimal.addEventListener('input', eventFunction('hex'));
decimal.addEventListener('input', eventFunction('dec'));