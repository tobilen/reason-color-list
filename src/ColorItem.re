let component = ReasonReact.statelessComponent "ColorItem";

let make color::(color: ColorData.color) _children => {
  ...component,
  render: fun self =>
    <div className="color-item">
      <div className="color-item__preview" style=(
        ReactDOMRe.Style.make
          backgroundColor::color.hexcode
          width::"100px"
          height::"50px"
          ()
      ) />
      <div className="color-item__hexcode">
        (ReasonReact.stringToElement color.hexcode)
      </div>
      <h2> (ReasonReact.stringToElement color.name) </h2>
    </div>
};