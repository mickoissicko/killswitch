from flask import Flask, render_template

app = Flask(__name__, template_folder='public')

@app.route('/')
def index():
    return render_template('index.htm')

@app.route('/t/')
def terminate():
    print("Terminate loaded!")
    return render_template('sucess.htm')

@app.route('/b/')
def back():
    return render_template('index.htm')

if __name__ == '__main__':
    app.run(host='127.0.0.1', port='80')

