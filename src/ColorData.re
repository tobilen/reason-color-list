type color = {
  name: string,
  hexcode: string,
};

let parseColorJson json :color =>
Json.Decode.{
  name: field "name" string json,
  hexcode: field "hexcode" string json
};