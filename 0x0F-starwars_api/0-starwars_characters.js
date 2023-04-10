#!/usr/bin/node
const request = require('request');

const asyncDisplayName = async url => {
  return new Promise((resolve, reject) => {
    request.get(url, (error, response, body) => {
      if (!error) resolve(JSON.parse(body).name);
      else reject(error);
    });
  });
};

request.get(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, async (error, response, body) => {
  if (!error) {
    const charactersUrl = JSON.parse(body).characters;
    for (const url of charactersUrl) {
      console.log(await asyncDisplayName(url));
    }
  }
});
