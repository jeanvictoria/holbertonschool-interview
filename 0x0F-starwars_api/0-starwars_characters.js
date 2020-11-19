#!/usr/bin/node

const request = require('request');
const episodeId = process.argv[2];
const movurl = 'https://swapi-api.hbtn.io/api/films/' + episodeId;

function listRightOrder(movurl) {
    request.get(movurl, (err, response, body) => {
        if (err) throw err;
        else {
            const chList = {};
            const characters = JSON.parse(response.body).characters;
            for (let i = 0; i < characters.length; i++) {
                request.get(characters[i], (err, response, body) => {
                    if (err) throw err;
                    else {
                        chList[i] = (JSON.parse(response.body).name);
                    }
                    if (characters.length === Object.keys(chList).length) {
                        for (let m = 0; m < Object.keys(chList).length; m++) {
                            console.log(chList[m]);
                        }
                    }
                });
            }
        }
    });
}
listRightOrder(movurl);
