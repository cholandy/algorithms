function mergeSort(arr, left, right) {
    if (right - left <= 1) {
        return;
    }
    var mid = parseInt((left + right) / 2);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);

    mergeArray(arr, left, mid, right);
    return;
}

function merge(left, right) {
    var ret = [];
    while (left.length || right.length) {
        if (left[0] < right[0] || right.length == 0) {
            ret.push(left.shift());
        } else {
            ret.push(right.shift());
        }
    }
    return ret;
}

function mergeSlow(arr) {
    if (arr.length <= 1) {
        return arr;
    }
    var mid = parseInt((arr.length) / 2);
    var left = arr.slice(0, mid);
    var right = arr.slice(mid);
    left = mergeSlow(left);
    right = mergeSlow(right);
    return merge(left, right);
}


var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
var size = input.shift();

console.log(mergeSlow(input, 0, size).join('\n'));