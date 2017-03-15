import tf
import  numpy as np

R1 = tf.transformations.translation_matrix([-0.3,0.5,0.7])
R2 = tf.transformations.rotation_matrix(0.02,[1,0,0])
R3 = tf.transformations.rotation_matrix(-0.01, [0,1,0])
R4 = tf.transformations.rotation_matrix(0.02, [0,0,1])


T3 = R3.dot(R4)
T2 = R2.dot(T3)
T1 = R1.dot(T2)
print T1

Tew = np.array([[0,1,0,10],[-1,0,0,0],[0,0,1,-1],[0,0,0,1]])
print 'Tew\n',Tew
Twe = np.linalg.inv(Tew)
Teb = np.array([[0,0,1,0],[0,1,0,0],[-1,0,0,0],[0,0,0,1]])
print 'Teb\n',Teb

Twb=Twe.dot(Teb)

Twb2 = Twb.dot(T1)
print  Twb2

Tbw = np.linalg.inv(Twb)
db_b = Tbw.dot(T1)

print  db_b

rpy = tf.transformations.euler_from_matrix(db_b)

print  rpy
