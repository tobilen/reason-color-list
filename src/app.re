type componentState = {colors: option (array ColorData.color)};

let component = ReasonReact.statefulComponent "App";

let dummyColors: array ColorData.color = [|
  ColorData.parseColorJson (
    Js.Json.parseExn {js|
      {
        "name": "blue",
        "hexcode": "#00FFFF"
      }
    |js}
  )
|];

let make ::title _children => {
  ...component,
  initialState: fun () :componentState => {
    colors: Some dummyColors
  },
  render: fun {state} => {
    let renderColors = switch (state.colors) {
      | Some colors => ReasonReact.arrayToElement (Array.map
          (fun (color: ColorData.color) => <ColorItem key=color.hexcode color=color />)
          colors
        )
      | None => ReasonReact.stringToElement "Loading"
    };
    <div className="App">
      <div className="App-header"> <h1> (ReasonReact.stringToElement "Iris Colors") </h1> </div>
      renderColors
    </div>
  }
};