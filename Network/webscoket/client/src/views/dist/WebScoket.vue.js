"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
exports.__esModule = true;
var vue_1 = require("vue");
var WebScoket = /** @class */ (function (_super) {
    __extends(WebScoket, _super);
    function WebScoket() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    WebScoket.prototype.data = function () {
        return {
            title: "测试 WebScoket 客户端"
        };
    };
    return WebScoket;
}(vue_1["default"]));
exports["default"] = WebScoket;
