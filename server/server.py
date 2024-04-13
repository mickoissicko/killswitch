from http.server import HTTPServer, BaseHTTPRequestHandler
from urllib.parse import parse_qs, urlparse

import platform
import os

class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        parsed_path = urlparse(self.path)
        query_params = parse_qs(parsed_path.query)

        if parsed_path.path == '/':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            with open('public/index.htm', 'rb') as file:
                self.wfile.write(file.read())

        elif parsed_path.path == '/t/':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()

            print("Terminate loaded!")

            if platform.system() == 'Windows':
                os.system("hnd.out.exe")
            else:
                os.system("hnd.out")

            with open('public/success.htm', 'rb') as file:
                self.wfile.write(file.read())

        elif parsed_path.path == '/b/':
            self.send_response(302)
            self.send_header('Location', '/')
            self.end_headers()

        else:
            self.send_response(404)
            self.send_header('Content-type', 'text/plain')
            self.end_headers()
            self.wfile.write(b'404 Not Found')

def run(server_class=HTTPServer, handler_class=Handler, addr="127.0.0.1", port=80):
    server_address = (addr, port)
    print("Server has been started")
    httpd = server_class(server_address, handler_class)
    httpd.serve_forever()

if __name__ == '__main__':
    print("Starting...")
    run()

